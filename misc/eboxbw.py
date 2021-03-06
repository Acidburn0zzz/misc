#!/usr/bin/env python

from datetime import datetime
import re
import sys
from urllib.request import urlopen
from urllib.error import URLError


VLCODE = ''

if __name__ == '__main__':
    if not bool(VLCODE):
        sys.stderr.write('error: VL code not specified\n')
        sys.exit(1)

    # fetch URL
    url = 'http://conso.ebox.ca/index.php'
    data = 'actions=list&DELETE_lng=fr&lng=fr&code={}'.format(VLCODE).encode()
    try:
        resp = urlopen(url, data=data)
    except URLError as err:
        if err.code == 403:
            sys.stderr.write('error: forbidden (probably too many attempts; retry later)\n')
            sys.exit(1)
        else:
            sys.stderr.write('error: unknown error (HTTP status: ' + err.code + ')\n')
            sys.exit(2)
    html = resp.read().decode('iso-8859-1')

    # verify if service is online
    if 'indisponible' in html:
        sys.stderr.write('error: service currently unavailable (retry later)\n')
        sys.exit(2)

    # verify if user is found
    if 'vlxxxxxx' in html:
        sys.stderr.write('error: invalid VL code (not found)\n')
        sys.exit(2)

    # find all stats
    m = re.findall(r'([0-9.]+) G<div id=\'total_off\'', html)
    if len(m) == 0:
        m = re.findall(r'<span class=\'txtdata\'><b>Total</b><br>([0-9.]+) G<br>', html)
        if len(m) == 0:
            sys.stderr.write('error: wrong page format\n')
            sys.exit(2)

    print('{} GiB'.format(m[0]))
