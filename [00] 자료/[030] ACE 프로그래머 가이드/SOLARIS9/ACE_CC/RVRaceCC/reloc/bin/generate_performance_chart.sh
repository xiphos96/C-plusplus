#!/bin/sh
#
# generate_performance_chart.sh,v 4.2 2002/05/06 18:38:56 bala Exp
#

gnuplot <<_EOF_ >/dev/null 2>&1
    set xdata time
    set timefmt '%Y/%m/%d-%H:%M'
    set xlabel 'Date (YYYYMMDD)'
    set ylabel 'Throughput (Requests/Second)'
    set terminal png small color
    set yrange [2000:12000]
    set output "$2"
    plot '$1' using 1:2 title '$3' w l
    exit
_EOF_
