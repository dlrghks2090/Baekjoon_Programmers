n = int(input())

i = 0
flag = 0
st = []
arr = []
sol = []
while i < n:
    tmp = int(input())
    arr.append(tmp)
    i = i + 1

num = 1
st.append(num)
sol.append('+')
for a in arr:
    if not st:
        num = num+1
        st.append(num)
        sol.append('+')

    if a == st[-1]:
        st.pop()
        sol.append('-')
    elif a < st[-1] or a < num:
        flag = 1
        break
    else:
        while st[-1] != a:
            num = num+1
            st.append(num)
            sol.append('+')
        st.pop()
        sol.append('-')
if flag == 0:
    for i in sol:
        print(i)
else:
    print("NO")