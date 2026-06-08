import pytest
import calc_dis

def test_dis():
	assert 0 == check2([], 0)
	assert 0 == check2([1], 1)
	assert 0 == check2([1,2], 2)
	assert 0 == check2([1,2,3], 3)
	assert 0 == check2([1,2,3,4], 4)
	assert 0 == check2([1,2,1,2,1], 5)
	assert 0 == check2([1,2,3,1,2,3,1], 7)
	assert 0 == check2([1,2,3,1,2,3,1,2], 8)

	assert 1 == check2([1,2,1,2], 4)
	assert 1 == check2([0,0,0,0], 4)
	assert 1 == check2([1,2,3,3,1,2,3,3], 8)
	assert 1 == check2([1,2,3,1,2,3], 6)
	assert 1 == check2([1,2,1,2,1,2,1,2], 8)
	assert 1 == check2([1,2,3,1,2,3,1,2,3], 9)