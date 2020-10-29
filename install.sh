#!/bin/bash
if [ -d "./bin" ]; then rm -Rf ./bin; fi && mkdir bin && cd bin && cmake .. && make && cd ..
