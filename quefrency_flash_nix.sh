#!/usr/bin/env nix-shell
#! nix-shell -i bash shell.nix --arg arm false
make keebio/quefrency/rev1_dgb:dgb:avrdude
