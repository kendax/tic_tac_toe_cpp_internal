FROM drogonframework/drogon:latest

COPY . /usr/src/drogo

WORKDIR /usr/src/drogo/build

RUN cmake ..
RUN make

ENV PORT "8080"
EXPOSE 8080

CMD ["./tic_tac_toe_cpp_internal"]