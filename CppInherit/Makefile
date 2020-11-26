all: main1 main2
	./main1
	./main2
main1:main1.c
	g++ -o main1 main1.c
main2:main2.c
	g++ -o main2 main2.c
.PHONY:clean
clean:
	rm -f main1 main2