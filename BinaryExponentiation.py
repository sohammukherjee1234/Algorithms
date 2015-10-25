def expo(a, b):
    if b == 1: return a
    elif b == 2: return a*a
    elif b % 2 == 0: return expo(expo(a, b/2),2)
    return a*expo(expo(a, (b-1)/2),2)

number, power = map(int, raw_input().rstrip().split())
print expo(number, power) if power != 0 else 1
