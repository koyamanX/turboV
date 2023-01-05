.. turboV documentation master file, created by
   sphinx-quickstart on Thu Jan  5 14:39:32 2023.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to turboV's documentation!
==================================

turboV is Out-of-Order superscalar processor written in NSL.
The goal of this docuemnt is to provide the internal design of turboV processor.

Useful Links
------------

turboV source code can be found at https://github.com/koyamanX/turboV

NSL Reference maunal can be obtained via https://www.overtone.co.jp/en/support/document/

NSL Tutorial can be found at https://www.overtone.co.jp/en/support/tutorial/

Development environment
-----------------------

turboV requires NSL core to convert NSL design to Verilog-HDL.
NSL core can be obtained from https://www.overtone.co.jp/en/products/nsl-core/
Docker image for all-in-one environment which includes NSL core, riscv cross compiler etc, are provided in https://hub.Docker.com/repository/Docker/koyamanx/turbov_dev

Quick start
-----------

Easy way to get started with turboV development is to use our Docker image.
run.sh below pulls pre-built Docker image from Docker Hub.
Or you can also manually build Docker image(takes some time) by yourself by invoking below.


.. _quick_start_guide:
.. code-block:: bash
   :caption: Quick start guide

   git clone --recursive https://github.com/koyamanX/turboV
   cd turboV

   # Enter Docker container
   ./run.sh

   mkdir build
   cd build
   cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=./

   # Build and install turboV simulator
   make install -j$(nproc)

   # To run riscv-tests suite, run below
   make test

.. Note::
   run.sh in :numref:`_quick_start_guide` pulls Docker image for Docker Hub or you can manually build Docker image.

   .. code-block:: bash

    cd turboV/image
    ./build.sh

Table of Contents
-----------------

.. toctree::
   :maxdepth: 2
   :caption: Introduction:

   sections/turboV

