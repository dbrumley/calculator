FROM debian:stable
RUN apt-get update && apt-get install -y build-essential libc6-dbg
WORKDIR /build
COPY . .
COPY tests/testsuite /testsuite
RUN make all && make coverage
CMD ['/build/bin/calculator']
