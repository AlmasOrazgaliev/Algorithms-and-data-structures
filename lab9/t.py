def is_person_teenager(n):
    if n>=12 and n<=17:
        return True
    else: return False

n = int(input())
if is_person_teenager(n):
    print('True')
else: print('False')
