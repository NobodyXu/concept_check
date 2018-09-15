#!/usr/bin/python3

import glob
import os
import sys
import subprocess

def invoke(*args):
    print(*args)
    subprocess.run(*args, check = True)
def get_cxx():
    if len(sys.argv) == 2:
        return sys.argv[1]
    else:
        return os.environ["CXX"]

cxx = get_cxx()
repo = os.path.dirname(os.path.realpath(__file__))
test = repo + "/test/"

for relative_path in ["/", "/concepts/operations/", "/concepts/member/", "/concepts/"]:
    # Since the test in this repository just do some compile-time checking, so it is only compiled to *.o.
    # By doing this, calls to the compiler can be chained.
    invoke([CXX, "-std=c++17", "-c"] + glob.glob(test + relative_path + "*.cc"))
