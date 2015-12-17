#! /usr/bin/env python

import os
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

QUALITY = '10'


def has_oggenc():
    def is_exe(fpath):
        return os.path.isfile(fpath) and os.access(fpath, os.X_OK)

    oggenc = 'oggenc.exe' if sys.platform == 'win32' else 'oggenc'

    if is_exe(oggenc):
        return True
    else:
        path = os.getenv('PATH').split(os.pathsep)
        for p in path:
            if is_exe(os.path.join(p, oggenc)):
                return True

    return False


def convert_file(flac_file):
    if not os.path.isfile(flac_file):
        print('{}: file not found'.format(flac_file))
        return

    if os.path.splitext(flac_file)[1] != '.flac':
        print('{}: not a flac'.format(flac_file))
        return

    subprocess.call(['oggenc', '-q', QUALITY, flac_file])


def main():
    if not has_oggenc():
        print('Error: oggenc not found')
        exit(-1)

    with ThreadPoolExecutor(max_workers=8) as e:
        for f in sys.argv[1:]:
            e.submit(convert_file, f)

if __name__ == '__main__':
    main()
