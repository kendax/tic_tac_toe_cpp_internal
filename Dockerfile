FROM drogonframework/drogon:latest

COPY . /usr/src/app

WORKDIR /usr/src/app/build

RUN cmake ..
RUN make

ENV PORT "8848"
EXPOSE 8848

CMD ["./app"]