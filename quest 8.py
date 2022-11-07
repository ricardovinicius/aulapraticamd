def euclidesextendido(x,y):
    if x == 0 :
        return y, 0,1
    mdc, x1,y1 = euclidesextendido (y%x, x)
    a = y1 - (y//x)*x1
    b = x1
    return mdc, a, b

def congruencia (x, y, n):

    x = (x%n)
    y = (y%n)
    u,v = 0,0
    d, u, v = euclidesextendido(x,n)
    x0= (u*(y//d)%n)

    if (x0 <0 ):
        x0= x0 +n
    if (y % d!= 0):
        print (-1)
        return
    for i in range(d):
        print ((x0+i*(n//d))%n, end = " ")

def getinput():
    
    print ("bem vindo! Insira seus valores (sem quebra de linha)" )
    a, b, c = input().split()

    a = int (a)
    b = int (b)
    c = int (c)

    congruencia (a,b,c)

getinput()
