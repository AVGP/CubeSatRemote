package ch.kripp.spaceapps.domain.Environment;

/**
 *
 * @author frank
 */
public class EnvironmentInfo {
    private String identifier;

    private String middlewareVersion;
    

    public String getMiddlewareVersion() {
        return middlewareVersion;
    }

    public void setMiddlewareVersion(String middlewareVersion) {
        this.middlewareVersion = middlewareVersion;
    }

    public String getIdentifier() {
        return identifier;
    }

    public void setIdentifier(String identifier) {
        this.identifier = identifier;
    }
}
