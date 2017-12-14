from	os		import	listdir, path
from	subprocess	import	run, PIPE
from	string		import	*
from	time		import	time

class bcolors:
    WORK = "\33[22;32m"
    FAIL = "\33[22;31m"

for file in listdir("mouli_maps"):
	begin = time()
	output = run(['./bsq', path.join("mouli_maps", file)], stdout=PIPE).stdout.decode()
	end = time()
	ref = open(path.join("mouli_maps_solved", file), "r").read()
	if (output == ref):
		print(bcolors.WORK + "[WORK] " + " in " + str(end - begin)[:4] + "s  --  " + file)
	else:
		print(bcolors.FAIL + "[FAIL] " + file)
