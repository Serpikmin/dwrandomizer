## Uncomment below and replace the filepaths!

# dwr: common/* /home/peter/dwrandomizer-wrapper/*.py*
# 	rm -rf /home/peter/dwrandomizer-wrapper/build
# 	rm -rf /home/peter/dwrandomizer-wrapper/dwr.cpython*
# 	gcc -fPIC -w -c common/*.c
# 	cp common/*.h .
# 	ar -rc /home/peter/dwrandomizer-wrapper/libdwr.a *.o
# 	python3 /home/peter/dwrandomizer-wrapper/setup.py build_ext --inplace
# 	mv dwr.cpython* /home/peter/dwrandomizer-wrapper/
# 	make clean

# clean:
# 	rm -rf /home/peter/make/*.o
# 	rm -rf /home/peter/make/build