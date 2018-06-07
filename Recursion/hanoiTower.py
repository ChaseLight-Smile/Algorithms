def hanoiTower(n, a, buffer, c):
    if(n == 1):
        print(a,"->",c)
        return
    hanoiTower(n-1, a, c, buffer)
    hanoiTower(1, a, buffer, c)
    hanoiTower(n-1, buffer, a, c)
hanoiTower(3, "a", "b", "c")
