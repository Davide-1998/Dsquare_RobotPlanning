#! /bin/bash

key="$1"

  case $key in 
   -v| --version)
		VERSION="$2"
     ;;
    *)
     VERSION=""
 	 ;;
  esac

out_name="Dsquare_RP.out"
 
g++ -o $out_name main.cpp ./Dubins/*.cpp ./Roadmap/*.cpp `pkg-config opencv$VERSION --cflags --libs`
./$out_name
