#!/usr/bin/perl

use warnings;
use strict;

die "Usage: [width] [height] [density]" unless (scalar(@ARGV) == 3);

my ($x, $y, $density) = @ARGV;

print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
  for (my $j = 0; $j < $x; $j++) {
    if (int(rand() * 100) < $density) {
      print "o";
    }
    else {
      print ".";
    }
  }
  print "\n";
}
