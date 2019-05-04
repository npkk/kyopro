import subprocess as sp
import argparse

parser = argparse.ArgumentParser(
    formatter_class=argparse.ArgumentDefaultsHelpFormatter)
parser.add_argument(
    '--questions', '-q', metavar='q', type=int, default=4,
    help='Numbers of questions')
args = parser.parse_args()

for char in range(ord('a'), ord('a') + args.questions):
    char = chr(char)
    sp.run([
        'cp',
        'lib/template.cc',
        'src/{}.cc'.format(char)
    ])