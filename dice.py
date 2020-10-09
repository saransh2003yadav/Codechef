import random # can be used to get random numbers
a= 'y'

while a == 'y' :
    x = random.randint(1,6)
    if x==1 :
        print('---------')
        print('[       ]')
        print('[   0   ]')
        print('[       ]')
        print('---------')
    if x==2 :
        print('---------')
        print('[       ]')
        print('[  0 0  ]')
        print('[       ]')
        print('---------')
    if x==3 :
        print('---------')
        print('[0      ]')
        print('[   0   ]')
        print('[      0]')
        print('---------')
    if x==4 :
        print('---------')
        print('[ 0   0 ]')
        print('[       ]')
        print('[ 0   0 ]')
        print('---------')
    if x==5 :
        print('---------')
        print('[ 0   0 ]')
        print('[   0   ]')
        print('[ 0   0 ]')
        print('---------')
    if x==6 :
        print('---------')
        print('[ 0   0 ]')
        print('[ 0   0 ]')
        print('[ 0   0 ]')
        print('---------')
    a = input('if you want to roll again press y :')


print()
input("Press any key to continue..........")
