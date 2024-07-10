# n=int(input())
# l1=[]
# mydict={}
# for i in range(n):
#     name=input()
#     c=l1.count(name)
#     l1.append(name)
#     if c==0:
#         mydict[i]='OK'
#     else:
#         mydict[i]=name+str(c)
# for i in mydict.values():
#     print(i)

n = int(input())
names = set()
name_count = {}
for i, name in enumerate(input() for _ in range(n)):
    if name in names:
        name_count[name] += 1
        print(name + str(name_count[name]))
    else:
        names.add(name)
        name_count[name] = 0
        print("OK")