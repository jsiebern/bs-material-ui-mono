#!/bin/bash
rm src/*
cp ../../output/reason/*.re src
pnpm run bs:build
rm src/*.bs.js