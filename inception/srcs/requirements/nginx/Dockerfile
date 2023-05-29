# Get the base image, in this case the oldest lts of debian os:
FROM	debian:buster

RUN		apt-get update && apt-get install -y nginx openssl

# Create a new ssl certificate as to allow the server to use the https protocol.
# req: This subcommand specifies that we want to use X.509 certificate signing request (CSR) management.
# -x509: This option specifies we want to make a self-signed certificate instead of generating a certificate signing request, as would normally happen.
# -sha256: This options specifies we want to use SHA-256 as the hash in our encryption.
# -node: Skip securing the certificate with a password, as nginx should be able to automatically read the file on restart, without sysadmin intervention.
# -days: Specify amount of days the certificate stays valid.
# -newkey rsa:4096: Tells the program to generate a certificate and key at the same time. Make the RSA 4096 bits long.
# -out: Path to the newly created certificate.
# -keyout: Path to the newly created private key.
# -subj: Directly give the certificate info, avoiding being prompted for it.
RUN		openssl req -x509 -sha256 -nodes \
		-days 369 -newkey rsa:4096 \
		-out /etc/ssl/certs/ntamayo-.crt \
		-keyout /etc/ssl/private/ntamayo-.key \
		-subj "/C=ES/ST=Andalusia/L=Malaga/O=42 School/OU=ntamayo-/CN=ntamayo-.42.fr"

COPY	./config/nginx.conf /etc/nginx/nginx.conf

EXPOSE	443

CMD		["nginx", "-g", "daemon off;"]
