# Using this as the base image
FROM drogonframework/drogon:latest

# Copying all project files to the container's /usr/src/drogo directory 
COPY . /usr/src/drogo

# Declaring the working directory inside the container
WORKDIR /usr/src/drogo/build

# Running the program's build commands
RUN cmake ..
RUN make

ENV PORT "8080"

# Open up port 8080 in the container to use for the program
EXPOSE 8080

# Command to run the program
CMD ["./tic_tac_toe_cpp_internal"]