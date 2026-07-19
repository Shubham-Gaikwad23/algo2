def parity(x):
	res = 0
	while x:
		x = x & (x-1)  # Drop the rightmost bit
        
		res = 1 ^ res
	return res

def count_set_bits(x):
    total = 0
    while x:
        x = x & (x-1)
        '''
        x = x & (x-1)  # Drop the rightmost set bit
        looking from the right side of the binary representation
        the first bit that is 1 is set to 0 and remaining is left as it is
        0111000
        0110000
        so we are effectively skipping over all consecutive 0 bits from right side
        To get the mask of the bit that is being set to 0 use
        x = x & ~(x-1)
          011100
        & 100100
          000100

        '''
        total = total + 1
    return total

print(parity(235))

# for i in range(1000):
#     print(count_set_bits(i), end='   ')