
L, C = map(int, input().split())

arr = []
arr = input().split()

mo = "aeiou"
mo = list(mo)

sol = [0 for _ in range(L)]
arr.sort()


def back(a, b):
    count = 0
    if a == L:
        for i in range(L):
            for k in mo:
                if sol[i] == k:
                    count += 1
        if count > 0 and L-count > 1:
            for idx in sol:
                print(idx, end='')
            print()
        return
    elif b >= C:
        return

    for j in range(b, C):
        sol[a] = arr[j]
        back(a+1, j+1)


back(0, 0)