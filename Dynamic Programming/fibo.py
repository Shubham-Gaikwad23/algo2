from time import time

def bottom_up_fibo(n):
	fib = [0, 1]
	for i in range(2, n+1):
		fib.append(fib[i-1] + fib[i-2])
	return fib[-1]

def memoized_fibo(n):
	global fib
	if fib[n] != -1:
		return fib[n]
	else:
		fib[n] = fibo(n-1) + fibo(n-2)
		return fib[n]

def fibo(n):
	if n==0:
		return 0
	elif n==1:
		return 1
	else:
		return fibo(n-1) + fibo(n-2)

def main():
	global fib
	for n in range(2, 40):
		start = time()
		fibo(n)
		diff1 = time() - start

		fib = [-1 for i in range(n+1)]
		fib[0] = 0
		fib[1] = 1
		start = time()
		memoized_fibo(n)
		diff2 = time() - start

		start = time()
		bottom_up_fibo(n)
		diff3 = time() - start


		print(n, int(diff1), int(diff2), int(diff3))

if __name__ == '__main__':
	main()