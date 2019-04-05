#!/usr/bin/env nix-shell
#! nix-shell -i bash shell.nix --arg arm false
make dz60:dgb:dfu
