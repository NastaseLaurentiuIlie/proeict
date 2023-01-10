FROM gcc:latest
WORKDIR /workdir
COPY myapp.cpp .
RUN gcc -o myapp myapp.cpp -lstdc++
CMD ["./myapp"]

