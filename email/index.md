Breaches
--------

 * _2015-10-19_, CIA Director John Brennan's AOL email compromise via socially-engineered AOL password reset
   [[link]](http://www.wired.com/2015/10/hacker-who-broke-into-cia-director-john-brennan-email-tells-how-he-did-it/)
 * _2014-11-24_, SONY email leaks. Apparently, the hack was made easier by phishing some employee passwords
   [[link]](http://www.tripwire.com/state-of-security/latest-security-news/sony-hackers-used-phishing-emails-to-breach-company-networks/)
 * _2012-07-12_, Yahoo (and Gmail and Hotmail) SQL injection hack which lead to revealed passwords
   [[link]](http://bits.blogs.nytimes.com/2012/07/12/yahoo-breach-extends-beyond-yahoo-to-gmail-hotmail-aol-users/?_r=1)
 * _2011-08-29_, Google's SSL MITM (possibly) by Iran, thorugh fake Google cert issued by allegedly invalidly created intermediate CA
   [[link]](https://googleonlinesecurity.blogspot.com/2011/08/update-on-attempted-man-in-middle.html)
 * _2010-01-12_, Google's network breach (possibly) by China
   [[link]](https://googleblog.blogspot.com/2010/01/new-approach-to-china.html)

CA untrustworthiness
--------------------

 * _2013-12-07_, One of the intermediate CAs created by ANSSI (France) misbehaved and issued a fake Google cert so they can monitor traffic within a network. 
   The fake cert was used in a commercial device apparently.
   [[link]](https://googleonlinesecurity.blogspot.com.au/2013/12/further-improving-digital-certificate.html)
 * _2013-09-13_, GCHQ redirects traffic using what has to be a fake cert (but not confirmed in the wild) suggesting compelling of CAs 
   [[link]](https://www.schneier.com/blog/archives/2013/09/new_nsa_leak_sh.html)
 * _2013-01-03_, Turkey CA realized they issued two bad intermediate CA certificates instead of normal SSL certificates
   [[link]](https://googleonlinesecurity.blogspot.co.uk/2013/01/enhancing-digital-certificate-security.html)
 * _2011-08-29_, Google's SSL MITM (possibly) by Iran, thorugh fake Google cert issued by allegedly invalidly created intermediate CA
   [[link]](https://googleonlinesecurity.blogspot.com/2011/08/update-on-attempted-man-in-middle.html)
 * _2010-08-27_, Talks about a newly appointed CA from UAE called Etisalat, who in the past served a fake Blackberry update to its customers or employees
   [[link]](http://www.slate.com/articles/technology/webhead/2010/08/the_internets_secret_back_door.html)

Papers
------
 
 * [Certified lies](http://dx.doi.org/10.1007/978-3-642-27576-0_20), by Christian Soghoian: Explains how CAs can be used to mount MITM attacks. Calls for better trust decisions regarding CAs.
 * Super-efficient aggregating history-independent persistent authenticated dictionaries, by Crosby
   + Introduces Persistent Authenticated Dictionaries, but doesn't solve the consistency check problem between different PAD versions.
 * Balloon: A forward-secure append-only persistent authenticated data structure
   + Introduces a PAD which relies on expensive monitoring to ensure consistency

Current CA work
---------------

 * Convergence
 * Perspectives
 * EFF's Sovereign Keys
 * OCSP
 * Keybase
 * CT
 * ECT
 * CONIKS
 * Balloon

Current email work
------------------

### Promising email work

 * [ProtonMail](https://protonmail.ch)
   + Their main problem is they haven't found a way to allow their users to verify the JS code they deliver
 * [whiteout.io](https://whiteout.io/#pricing * [whiteout.io](https://whiteout.io/#pricing * [whiteout.io](https://whiteout.io/#pricing)
   + Seems like they do end-to-end crypto with wrapped secret keys

### Snake-oil email work

We might be a little rough on these guys here.

 * [Cisco Email Encryption](http://www.cisco.com/c/en/us/products/security/email-encryption/index.html#)
   + Store encryption keys in your cloud for everybody and call yourself secure.
   + They use email-based authentication to decrypt "secure" emails
 * [LavaBit](http://lavabit.com/)
   + They seemed like good guys, but why did they have to store the private keys in plaintext?
   + If they were compromised `=>` all private keys were compromised `=>` all emails compromised

In general, we don't like PGP because users do not understand how to use it.

 * PGP-based browser extensions
   + [Mymail-Crypt for GMail](https://chrome.google.com/webstore/detail/mymail-crypt-for-gmail/jcaobjhdnlpmopmjhijplpjhlplfkhba)
   + [Mailvelope](https://chrome.google.com/webstore/detail/mailvelope/kajibbejlbohfaggdiogboambcijhkke)
   + [PGP anywhere](https://chrome.google.com/webstore/detail/pgp-anywhere/cdlcdnmhcodhagbmljapgbjdimjckilb)
 * PGP-based mail clients
   + [RoundCube with OpenPGP.js](https://github.com/qnrq/rc_openpgpjs/)
   + [https://encrypt.to/](https://encrypt.to/)
   + [PGpgp for BlackBerry](http://pawelgorny.com/PGpgp/)
 
### Email libraries


 * [OpenPGPjs](http://openpgpjs.org/)

Future work
-----------

### Security

 * Need transparency, consistency (append-only) and Byzantine fault tolerant consensus for user PK bindings
 * Need to deal with mailing lists
 * Need to deal with encrypted spam
 * Need to deal with group messaging?
 * Need to deal with anonymity?
 * Need to deal with metadata hiding?

### Usability

### Adoption

 * Need many ways for users to save/backup (escrow) their secret key
 * Need an incremental adoption plan.
   + Adoption depends on adoption: If people don't use your system, other people won't use it either.

