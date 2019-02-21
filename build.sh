#!/bin/bash
pwd=$(pwd)

git pull
rush update
rm -rf output

cd tools/json-schema-parser
pnpm run build

cd $pwd

cd tools/component-extractor
pnpm run build

cd $pwd

cd tools/binding-generator
pnpm run build

cd $pwd

cd tools/withstyles-ppx
pnpm run build

cd $pwd