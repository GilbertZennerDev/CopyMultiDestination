"""
the goal is to make an app which can copy paste the same source to multiple destinations

python app.py src dest1 ... dest2
"""

import sys
import subprocess as sp

def main():
	av = sys.argv
	ac = len(av)
	if ac < 3: exit()
	src = av[1]
	dests = av[2:]
	for dest in dests: sp.run(f"cp -r {src} {dest}", shell=True)

if __name__ == '__main__': main()
