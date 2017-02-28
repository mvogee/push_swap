import random

nums = input('how many numbers?: ')
array=[];
array = random.sample(range(0, nums), nums)
for i in array:
	print i,

