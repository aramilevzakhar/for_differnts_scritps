# Математическое ожидание и дисперсия
# n, m = list(map(int, input().split(' ')))
# print(n, m)
# x = input()
# inp = """
# n, m = 2, 4
# xn = '-1.00000 1.00000'
# xn = [float(x) for x in input().split(' ')]
# xn = [float(x) for x in xn.split(' ')]
# print(xn)s
# E1 = sum(xn) / n
# D1 = ((sum([(el - E1)**2 for el in xn]))/n) * (n/(n - 1))
# |e2 - e1| / max(1 | e1) <= 10**-6
# |d2 - d1| / max(1 | d1) <= 10**-6
# E1 = sum(xn) + sum(xm) / n
# E2 = (10**-6)*(max(1, E1)) + E1
# E2 = (sum(xn) + sum(xm)) / (m)
# sum(xn) = E2*m - sum(xm)
# sum(xn) = E1*n
# E2*m - sum(xm) = E1*n
# E2 = (E1*n + sum(xm))/m
# E2 = (E1*n)/m
# print(E1, E2)
# D2 = (10**-6)*(max(1, D1))
# print(summ_m_n / (n-m))
# n_m = xn[n::]
# print(n_m)
# if (sum(n_Vm) == 0):
# 	print('YES')
# 	# print(' '.join(list(map(str, n_m))))
# else:
# 	print('NO')

# K градиент
# string = '''
# 7 2
# 2 10 7 20
# 3 50 5 40
# '''
# n, m = list(map(int, string.split('\n')[0]).split(' '))
# string = [ [int(p) for p in el.split()] for el in string.split('\n') if len(el) > 0 ]

n = input()
string = []
print(n)

# print(string.remove())
# string = ' '.join(string).split()
# string = list(filter(None, string))
# string = string.remove("")
n = string[0][0]
m = string[0][1]

pole = [0] * n





# print(string[1::])
for elem in string[1::]:
	i1 = elem[0] - 1
	i2 = elem[2] - 1
	pole[i1] = elem[1]
	pole[i2] = elem[3]

	s_sum = (elem[3] - elem[1]) / (elem[2] - elem[0])
	# print('s_sum: ', s_sum)
	# print('pole: ', pole)
	# print(pole[i1], pole[i2])
	
	for i in range(elem[0] - 1, elem[2] - 1):
		pole[i + 1] = pole[i] + s_sum
# print(n, m)

# print(pole)
for el in pole:
	print('%.5f' % el, end=' ')

# print(n, m)




