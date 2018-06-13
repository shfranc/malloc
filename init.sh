#!/bin/bash
export DYLD_LIBRARY_PATH=$(pwd)
export DYLD_INSERT_LIBRARIES="libft_malloc.so"
export DYLD_FORCE_FLAT_NAMESPACE=1
