#!/bin/sh
ifconfig | grep "ether\|HWaddr" | cut -c -31 | cut -c15-
