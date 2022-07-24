#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/alexandr_broslavsky/Desktop/c++/NewGame/MyGame/BuildMyGame
  make -f /Users/alexandr_broslavsky/Desktop/c++/NewGame/MyGame/BuildMyGame/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/alexandr_broslavsky/Desktop/c++/NewGame/MyGame/BuildMyGame
  make -f /Users/alexandr_broslavsky/Desktop/c++/NewGame/MyGame/BuildMyGame/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/alexandr_broslavsky/Desktop/c++/NewGame/MyGame/BuildMyGame
  make -f /Users/alexandr_broslavsky/Desktop/c++/NewGame/MyGame/BuildMyGame/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/alexandr_broslavsky/Desktop/c++/NewGame/MyGame/BuildMyGame
  make -f /Users/alexandr_broslavsky/Desktop/c++/NewGame/MyGame/BuildMyGame/CMakeScripts/ReRunCMake.make
fi

