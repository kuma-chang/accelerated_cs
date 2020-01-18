# E --> N
def e_n(n):
    return (n/2)

# N --> Z
def n_z(n):
    if n == 1:
        return 0
    elif n%2 == 0:
        return n/2
    else:
        return (n-1)/(-2)

# GCD
def gcd(m,n):
    if m%n == 0:
        return n 
    else:
        return gcd(n, m%n)

# N --> Q+
def n_q_prep(n):
    counter = 0
    layer = 0
    while counter < n:
        counter = counter + (layer + 1)
        layer += 1
    order = n - (counter - layer)
    if layer%2 != 0:
        p = (layer + 1 - order)
        q = order
    else:
        p = order
        q = (layer + 1 - order)
    return (p,q)

def n_q(n):
    counter = 0
    x = 1
    while counter < n:
        p = n_q_prep(x)[0]
        q = n_q_prep(x)[1]
        if gcd(p,q) == 1:
            x += 1
            counter += 1
        else:
            x += 1
    return p/q
            



# Z --> Q
def z_q(n):
    if n == 0:
        return 0
    elif n > 0:
        return n_q(n)
    elif n < 0:
        return n_q((n*-1))*(-1)

# E --> Q
def e_q(n):
    if n == 2:
        return 0
    elif (n/2)%2 != 0:
        return z_q((((n/2)-1)/2))
    else:
        return  z_q(((n/2)/2)*(-1))

def e_q2(n):
    return z_q(n_z(e_n(n)))



for x in range(1,11):
    print(n_q(x))




