set -e

#go somewhere safe
cd /tmp

#get teh source to base APR 1.4.6
curl -L -O http://archive.apache.org/dist/apr/apr-1.4.6.tar.gz

#extract it and go into the source
tar -xzvf apr-1.4.6.tar.gz
cd apr-1.4.6

#configure make make install
./configure
make
sudo make install

cd /tmp
rm -rf apr-1.4.6 apr-1.4.6.tar.gz

# do the same apr-util
curl -L -O http://archive.apache.org/dist/apr/apr-util-1.4.1.tar.gz

# extract
tar -xzvf apr-util-1.4.1.tar.gz
cd apr-util-1.4.1

#configure make make install
./configure --with-apr=/usr/local/apr
make
sudo make install

#clean up
cd /tmp
rm -rf apr-util-1.4.1* apr-1.4.6*