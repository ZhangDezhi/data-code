import platform
print(platform.system())

if(platform.system()=='Windows'):
    print('Windows系统')
elseif(platform.system()=='Linux'):
    print('Linux系统')
else:
    print('其他')