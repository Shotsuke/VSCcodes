class Link:
    empty = ()

    def __init__(self, first, rest=empty):
        self.first = first
        self.rest = rest

    def __repr__(self):
        res = "< "+str(self.first)
        t = self.rest
        while t:
            res += ' '+str(t.first)
            t = t.rest
        res += ' >'
        return res


def reverse(lnk):
    if lnk.rest is Link.empty:
        return lnk

    result = reverse(lnk.rest)
    lnk.rest.rest = lnk
    lnk.rest = ()
    return result


def merge(lnk1, lnk2):
    while lnk1 is not Link.empty:
        rst1, rst2 = lnk1.rest, lnk2.rest
        lnk1.rest, lnk2.rest = lnk2, lnk1.rest
        lnk1, lnk2 = rst1, rst2
