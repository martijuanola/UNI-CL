#! /bin/bash

# location of this script (should be the same than asl/ and common/)
BASEDIR=$(dirname $0)

# create temporary dir in /tmp
TMPDIR=`mktemp -d`

# copy all code to tmp dir
cp -r $BASEDIR/asl $BASEDIR/common $TMPDIR
pushd $TMPDIR/asl >& /dev/null

# compile in /tmp
make pristine
make antlr
make -j8

# go back and copy compilation results to original dir
popd >& /dev/null
mv $TMPDIR/asl/*.o $TMPDIR/asl/asl $BASEDIR/asl/
mv $TMPDIR/common/*.o $BASEDIR/common

# clean up
rm -rf $TMPDIR

