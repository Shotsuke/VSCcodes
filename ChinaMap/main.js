window.onload = function () {
    const chart = echarts.init(document.querySelector("#china-map"));
    const oBack = document.querySelector("#back");

    let mapCaches = {};
    let childParentMapObj;

    function getAreaMap(areaCode, isFull) {
        return axios
            .get("http://42.192.232.58:3000/proxy/areas_v2/bound/" + areaCode + (isFull ? "_full" : "") + '.json?proxy_key=7f297416175d8b022098ded9548eb276')
            .then(function (res) {
                return Promise.resolve(res.data);
            });
    }

    oBack.onclick = function () {
        loadMap(childParentMapObj.map, childParentMapObj.name, {
            code: childParentMapObj.code,
            isFull: childParentMapObj.isFull
        });

        if(childParentMapObj.map !== 'china') {
            childParentMapObj = childParentMapObj.parent;

            oBack.innerHTML = "返回" + childParentMapObj.name;
        } else {
            childParentMapObj = null;

            oBack.style.setProperty('display', 'none');
        }
    };

    loadMap("china", "中国", {
        code: 100000,
        isFull: true
    });

    // 加载相应的地图
    function loadMap(map, name, { code, isFull }) {
        let promise = Promise.resolve();

        if (!mapCaches[map]) {
            promise = getAreaMap(code, isFull).then((mapData) => {
                echarts.registerMap(map, mapData);

                mapCaches[map] = mapData;
            });
        }

        promise.then(() => {
            const option = {
                title: {
                    text: name,
                    left: "center",
                },
                series: [
                    {
                        name: name,
                        type: "map",
                        map,
                        roam: true, // 是否开启鼠标缩放和平移漫游
                        itemStyle: {
                            // 地图区域的多边形 图形样式
                            normal: {
                                // 是图形在默认状态下的样式
                                label: {
                                    show: true, //是否显示标签
                                    textStyle: {
                                        color: "rgba(255,255,255,0)",
                                    },
                                },
                            },
                        },
                        aspectScale: map === 'china' ? 0.75 : 1,
                        top: "10%", //组件距离容器的距离
                    },
                ],
            };

            chart.clear();
            chart.setOption(option);

            chart.off("click");
            chart.off("dblclick");

            chart.on("click", function (param) {
                if(param.name !== (childParentMapObj || {}).name) {
                    const mapData = mapCaches[map];

                    if (mapData) {
                        const mapInfo = mapData.features.find(m => {
                            return m.properties.name === param.name;
                        });
                        const properties = mapInfo.properties;

                        loadMap(properties.adcode, properties.name, {
                            code: properties.adcode,
                            isFull: properties.level !== 'district'
                        })
                    }

                    if (!childParentMapObj) {
                        oBack.style.setProperty('display', 'block');
                    } else {
                        oBack.innerHTML = "返回" + name;
                    }
                    
                    childParentMapObj = {
                        map, 
                        name,
                        code,
                        isFull,
                        parent: childParentMapObj
                    };
                }
            });
        });
    }
}
