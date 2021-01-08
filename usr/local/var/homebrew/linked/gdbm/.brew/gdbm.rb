class Gdbm < Formula
  desc "GNU database manager"
  homepage "https://www.gnu.org/software/gdbm/"
  url "https://ftp.gnu.org/gnu/gdbm/gdbm-1.18.1.tar.gz"
  mirror "https://ftpmirror.gnu.org/gdbm/gdbm-1.18.1.tar.gz"
  sha256 "86e613527e5dba544e73208f42b78b7c022d4fa5a6d5498bf18c8d6f745b91dc"
  license "GPL-3.0"
  revision 1

  # --enable-libgdbm-compat for dbm.h / gdbm-ndbm.h compatibility:
  #   https://www.gnu.org.ua/software/gdbm/manual/html_chapter/gdbm_19.html
  # Use --without-readline because readline detection is broken in 1.13
  # https://github.com/Homebrew/homebrew-core/pull/10903
  def install
    args = %W[
      --disable-dependency-tracking
      --disable-silent-rules
      --enable-libgdbm-compat
      --without-readline
      --prefix=#{prefix}
    ]

    system "./configure", *args
    system "make", "install"

    # Avoid conflicting with macOS SDK's ndbm.h.  Renaming to gdbm-ndbm.h
    # matches Debian's convention for gdbm's ndbm.h (libgdbm-compat-dev).
    mv include/"ndbm.h", include/"gdbm-ndbm.h"
  end

  test do
    pipe_output("#{bin}/gdbmtool --norc --newdb test", "store 1 2\nquit\n")
    assert_predicate testpath/"test", :exist?
    assert_match /2/, pipe_output("#{bin}/gdbmtool --norc test", "fetch 1\nquit\n")
  end
end
