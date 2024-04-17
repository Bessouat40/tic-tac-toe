.PHONY: test

test:
	docker build -t cpp .
	docker run -it cpp