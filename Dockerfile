FROM debian:stable
RUN apt-get update && apt-get install -y build-essential libc6-dbg
WORKDIR /build
COPY . .
RUN make all 
CMD ['/build/calculator']
