eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;  

# ******************************************************************
#      Author: Chad Elliott
#        Date: 6/17/2002
#         mwc.pl,v 1.2 2002/07/09 12:30:46 elliott_c Exp
# ******************************************************************

# ******************************************************************
# Pragma Section
# ******************************************************************

use strict;
use Cwd;
use File::Basename;

my($basePath) = getExecutePath($0) . "/MakeProjectCreator";
unshift(@INC, $basePath . "/modules");

require Driver;

# ************************************************************
# Data Section
# ************************************************************

my(@creators) = ('GNUWorkspaceCreator',
                 'NMakeWorkspaceCreator',
                 'VC6WorkspaceCreator',
                 'VC7WorkspaceCreator',
                 'BorlandWorkspaceCreator',
                 'GHSWorkspaceCreator',
                 'EM3WorkspaceCreator',
                 'VA4WorkspaceCreator',
                );

# ************************************************************
# Subroutine Section
# ************************************************************

sub which {
  my($prog)   = shift;
  my($exec)   = "$prog";
  my($part)   = "";
  my($isWin)  = ($^O eq "MSWin32");
  my($envSep) = ($isWin ? ";" : ":");

  if (defined $ENV{'PATH'}) {
    foreach $part (split(/$envSep/, $ENV{'PATH'})) {
      $part .= "/$prog";
      if ( -x $part ) { 
        $exec = $part;  
        last;
      }
    }  
  }    
       
  return $exec;
}


sub getExecutePath {
  my($prog) = shift;
  my($loc)  = "";   

  if ($prog ne basename($prog)) {
    if ($prog =~ /^[\/\\]/ ||
        $prog =~ /^[A-Za-z]:[\/\\]?/) {
      $loc = dirname($prog);
    }
    else {
      $loc = getcwd() . "/" . dirname($prog);
    }
  }  
  else {
    $loc = dirname(which($prog));
  }
   
  if ($loc eq ".") {
    $loc = getcwd();
  }
   
  if ($loc ne "") {
    $loc .= "/";   
  }
   
  return $loc;
}


# ************************************************************
# Subroutine Section
# ************************************************************

my($driver) = new Driver($basePath, basename($0), @creators);
exit($driver->run(@ARGV));
