.PHONY: test play

test:
	docker build -t cpp .
	docker run -it cpp

play: 
	docker run -it cpp