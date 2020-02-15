#!/usr/bin/env python3

import sys
import os.path

# Fill in the missing routines, using the Java versions
# from lab4/08X and 10X as prototypes.
#
# read_integer_graph()
def read_integer_graph(gname):
    graph = {}
    int_list = []
    with open(gname + ".ig", 'r') as input_file:
        for line in input_file:
            words = line.split()
            for word in words:
                int_list.append(word)
        for i in range(len(int_list) - 2):
            if i % 2 == 0:
                v1 = int_list[i+2]
            else:
                v2 = int_list[i+2]
                if v1 in graph:
                    graph[v1].append(v2)
                else:
                    graph[v1] = [v2]
                if v2 in graph:
                    graph[v2].append(v1)
                else:
                    graph[v2] = [v1]
    return graph

# read_string_graph()
def read_string_graph(gname, sep):
    graph = {}
    int_list = []
    with open(gname + ".sg", 'r') as input_file:
        for line in input_file:
            words = line.split()
            for word in words:
                int_list.append(word)
        for i in range(len(int_list)):
            if i % 2 == 0:
                v1 = int_list[i]
            else:
                v2 = int_list[i]
                if v1 in graph:
                    graph[v1].append(v2)
                else:
                    graph[v1] = [v2]
                if v2 in graph:
                    graph[v2].append(v1)
                else:
                    graph[v2] = [v1]
    return graph

#
# write_dot_graph()
def write_dot_graph(gname, g):
    f= open(gname + ".dot","w+")
    f.write("graph " + gname + " {\n")

    visited = []
    for v in g:
        for w in g[v]:
            if not w in visited:
                f.write("\"" + v + "\" -- \"" + w + "\"\n")
            visited.append(v)

    f.write("}")
    f.close()

#


def usage():
  print('usage: ./graph.py [ file.ig | file.sg sep ]')    
  exit(0)

def main():
  if len(sys.argv) < 2: usage()    
  f = sys.argv[1]
  gname,kind = os.path.splitext(f)
  if kind == '.ig':
    if len(sys.argv) != 2: usage()
    g = read_integer_graph(gname)
  elif kind == '.sg':
    if len(sys.argv) != 3: usage()
    g = read_string_graph(gname,sys.argv[2])
  else: usage()
  write_dot_graph(gname,g)
  
if __name__ == '__main__':
  main()
