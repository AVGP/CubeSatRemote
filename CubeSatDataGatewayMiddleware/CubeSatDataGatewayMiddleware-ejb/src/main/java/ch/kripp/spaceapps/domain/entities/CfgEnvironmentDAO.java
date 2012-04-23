package ch.kripp.spaceapps.domain.entities;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "cfg_environment")
public class CfgEnvironmentDAO {

    @Id
    private String identifier;

    @Column
    private String middleware_version;


    public String getMiddleware_version() {
        return middleware_version;
    }

    public void setMiddleware_version(String middleware_version) {
        this.middleware_version = middleware_version;
    }

    public String getIdentifier() {
        return identifier;
    }

    public void setIdentifier(String identifier) {
        this.identifier = identifier;
    }
}
