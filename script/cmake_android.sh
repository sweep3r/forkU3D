#!/usr/bin/env bash
#
# Copyright (c) 2008-2022 the Urho3D project.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#

$(dirname $0)/cmake_generic.sh "$@" \
-D ANDROID=1 \
-D ANDROID_PLATFORM=35 \
-D ANDROID_NDK=/Users/hd/Library/Android/sdk/ndk/29.0.14206865 \
-D CMAKE_TOOLCHAIN_FILE=/Users/hd/Library/Android/sdk/ndk/29.0.14206865/build/cmake/android.toolchain.cmake \
-D URHO3D_LIB_TYPE=SHARED \
-D URHO3D_SAMPLES=0 \
-D URHO3D_PCH=0 \
-D URHO3D_SSE=0 \
-D URHO3D_IK=0 \
-D URHO3D_NETWORK=1 \
-D URHO3D_PHYSICS=1 \
-D URHO3D_PHYSICS2D=1 \
-D URHO3D_NAVIGATION=1 \
-D URHO3D_URHO2D=1 \
-D URHO3D_TOOLS=0 \
-D URHO3D_WEBP=0 \
-D URHO3D_FILEWATCHER=0 \
-D URHO3D_ANGELSCRIPT=1 \
-D URHO3D_LUA=0 \
-D URHO3D_LUAJIT=0 \
# Would prefer populate a build folder that we can run make on, with the different abis, 
# rather than a build folder per abi, but this var is used in e.g. top level cmake file.
# So, one at at time, passed on command line, for the moment
#-D ANDROID_ABI=x86_64
#-D ANDROID_ABI=arm64-v8a



# vi: set ts=4 sw=4 expandtab:
