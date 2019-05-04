import subprocess as sp
import argparse

parser = argparse.ArgumentParser(
    formatter_class=argparse.ArgumentDefaultsHelpFormatter)
parser.add_argument(
    '--name', '-n', type=str, default=None,
    help='Name of archive')
args = parser.parse_args()

if args.name is None:
    print('Name should be entered')

sp.run([
    'mkdir',
    'archives/{}'.format(args.name)
])
sp.run([
    'mv',
    'src/*.cc',
    'archives/{}/'.format(args.name)
])
sp.run([
    'rm',
    '-r',
    'src/*'
])