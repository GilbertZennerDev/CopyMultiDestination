"""
the goal is to make an app which can copy paste the same source to multiple destinations

python app.py src dest1 ... dest2
"""

import sys
import shutil

def main():
	av = sys.argv
	ac = len(av)
	if ac < 4: exit()
	src = av[2]
	dests = av[3:]
	if av[1] == '-file':
		try:
			for dest in dests: shutil.copy(src, dest)
		except Exception as e: print(e); exit()
	elif av[1] == '-folder':
		try:
			for dest in dests: shutil.copytree(src, dest)
		except Exception as e: print(e); exit()
	else: print("Arg1 must be -file or -folder")

if __name__ == '__main__': main()
